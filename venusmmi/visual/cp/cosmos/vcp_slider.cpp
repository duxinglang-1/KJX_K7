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
*  vcp_slider.cpp
*
* Project:
* --------
*  VenusMMI
*
* Description:
* ------------
*  Slider component
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
 * removed!
*
 * removed!
 * removed!
 * removed!
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include "vcp_slider.h"
#include "mmi_rp_srv_venus_component_slider_def.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_image_button.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_control.h"
#include "vfx_draw_context.h"
#include "vfx_image_src.h"
#include "vfx_frame.h"
#include "vcp_state_image.h"
#include "vadp_sys_trc.h"
#include "vfx_keypad.h"

/***************************************************************************** 
* Define
*****************************************************************************/
// SWLA logs
#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__  && __VENUS_SWLA_DBG_ON__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif 
	

#define FLOAT_EPSILON 0.000001
#define VCP_SLIDER_TRACK_MARGIN 3

/***************************************************************************** 
* Class VcpSliderBarThumb
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpSliderBarThumb", VcpSliderBarThumb, VcpImageButton);

VfxBool VcpSliderBarThumb::onPenInput(VfxPenEvent &event)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SoP", SA_start); 
#endif	
    VcpSlider *slider = (VcpSlider*)getParentFrame(); 
    VfxS32 position;

    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if(VCP_SLIDER_LAYOUT_HORZ == slider->getLayout())
        {
            position = getPos().x;
        }
        else
        {
            position = getPos().y;
        }
        VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_PEN_INPUT, event.type, position);
        VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_EMITTING_PEN_DOWN);
        slider->m_signalThumbPressed.postEmit(slider, slider->PositionToValue(position));
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if(VCP_SLIDER_LAYOUT_HORZ == slider->getLayout())
        {
            position =     event.getRelPos(slider).x;                
        }
        else
        {
            position =     event.getRelPos(slider).y;        
        }
        VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_PEN_INPUT, event.type, position);
        VfxFloat newValue = slider->PositionToValue(position);
        VfxFloat oldValue = slider->getCurrentValue();
        VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_PEN_VALUE_UPDATE, (VfxS32)(oldValue*100), (VfxS32)(newValue*100));

        slider->setCurrentValue(newValue);
        if(slider->getTotalDiscreteStepsForPen())
        {
            if(slider->getCurrentValue() == oldValue)   // Skip signals if value didn't change, in discrete step mode.
            {
                VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_SIGNAL_SKIP_DISCRETE);
#if defined(__MAUI_SOFTWARE_LA__)
				SLA_CustomLogging("SoP", SA_stop); 
#endif	
                return VcpImageButton::onPenInput(event);
            }
        }
        VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_EMITTING_PEN_MOVE, (VfxS32)(100*slider->getCurrentValue()));
        slider->m_signalThumbDrag.postEmit(slider, slider->getCurrentValue());
        slider->m_signalUserChangedValue.emit((VfxObject*)this, oldValue, slider->getCurrentValue()); // backward compatibility
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP ||
        event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        if(VCP_SLIDER_LAYOUT_HORZ == slider->getLayout())
        {        
            position = getPos().x;
        }
        else
        {     
            position = getPos().y;
        }
        VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_PEN_INPUT, event.type, position);

        VFX_LOG(VFX_INFO2, VCP_SLIDER_THUMB_EMITTING_PEN_UP, (VfxS32)(100*slider->getCurrentValue()));
        slider->m_signalThumbDrag.postEmit(slider, slider->getCurrentValue());
        slider->m_signalThumbReleased.postEmit(slider, slider->getCurrentValue());
        slider->m_signalUserChangedValue.emit((VfxObject*)this, slider->getCurrentValue(), slider->getCurrentValue());
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SoP", SA_stop); 
#endif		
    return VcpImageButton::onPenInput(event);
}


/***************************************************************************** 
* Class VcpSliderBarView
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpSliderBarView", VcpSliderBarView, VfxControl);
VcpSliderBarView::VcpSliderBarView():
    m_divider(0),
    m_trackBgImg(VCP_IMG_SLIDER_HRZT_BG),
    m_trackCompletedPartImg(VCP_IMG_SLIDER_HRZT_H),
	m_trackImgType(VCP_SLIDER_SEPARATED_TRACK_IMG)

{

}

VcpSliderBarView::~VcpSliderBarView()
{

}

void VcpSliderBarView::onInit()
{
    VfxControl::onInit();
}

VfxBool VcpSliderBarView::onPenInput(VfxPenEvent &event)
{
    return VFX_FALSE;
}

void VcpSliderBarView::onDraw(VfxDrawContext &dc)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SoD", SA_start); 
#endif
    VfxControl::onDraw(dc);

    VfxS32 w = getSize().width;
    VfxS32 h =  getSize().height;
    VfxSize slider_size = getParentFrame()->getSize();
    VfxFloat ratio;
    VfxS32 div = m_divider;
    if(w>h) // Horizontal layout
    {
        dc.drawResizedImage(VfxRect(0, 0, w, h), m_trackBgImg);
    }
    else // Vertical layout
    {
        dc.drawResizedImage(VfxRect(0, 0, w, h), m_trackBgImg);
    }
    if(m_trackImgType == VCP_SLIDER_SINGLE_TRACK_IMG)
    {
#if defined(__MAUI_SOFTWARE_LA__)
			SLA_CustomLogging("SoD", SA_stop); 
#endif			
		return;
    }
    else
    {
        VfxSize imgSize = m_trackCompletedPartImg.getSize();
        if(w>h) // Horizontal layout
        {            
            ratio = ((VfxFloat)m_divider) / ((VfxFloat)(slider_size.width));            
            div = m_divider - (VfxS32)(((VfxFloat)(VCP_SLIDER_TRACK_MARGIN<<1))*ratio);
            
            if(div < imgSize.width)
            {
                 if(div > 0)
                 {
                      div = imgSize.width;
                 }
            }
            dc.drawResizedImage(VfxRect(0, 0, div, h), m_trackCompletedPartImg);
        }
        else // Vertical layout
        {  
            ratio = ((VfxFloat)m_divider) / ((VfxFloat)(slider_size.height));            
            div = m_divider - (VfxS32)(((VfxFloat)(VCP_SLIDER_TRACK_MARGIN<<1))*ratio);
            div = div < imgSize.height ? 0 : div;
            dc.drawResizedImage(VfxRect(0, h - div, w, m_divider ), m_trackCompletedPartImg);
        }
    }
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SoD", SA_stop); 
#endif	
}

/***************************************************************************** 
* Class VcpSlider
*****************************************************************************/
 VFX_IMPLEMENT_CLASS("VcpSlider", VcpSlider, VfxControl);
VcpSlider::VcpSlider():
    m_mode(VCP_SLIDER_MODE_NON_INTERACTIVE),
    m_state(VFX_TRUE),
    m_length(0),
    m_unitStop(0),
    m_cValue(0),
    m_max(1),
    m_min(0),
    m_layout(VCP_SLIDER_LAYOUT_HORZ),
#if defined(VCP_SLIDER_KEY_HANDLING)
    m_discreteStepsForKey(10),
#endif
    m_discreteStepsForPen(0),
    m_track(NULL),
    m_thumb(NULL)
{
}

VcpSlider::~VcpSlider()
{
}

void VcpSlider::onInit()
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SoI", SA_start); 
#endif
	VfxControl::onInit();
    VcpSliderBarView *track;
    VcpSliderBarThumb *thumb;

	VFX_OBJ_CREATE(track, VcpSliderBarView, this);
	VFX_OBJ_CREATE(thumb, VcpSliderBarThumb, this);
    VfxImageSrc thumbImg(VCP_IMG_SLIDER_THUMB_CTRL);
	thumb->setSize(thumbImg.getSize());
	thumb->setImage(VcpStateImage(VCP_IMG_SLIDER_THUMB_CTRL));
   thumb->setAnchor(0.5,0.5);
   thumb->setAutoAnimate(VFX_FALSE);

   setTrack(track);
   setThumb(thumb);

#if defined(VCP_SLIDER_KEY_HANDLING)	
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_UP, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_DOWN, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_LEFT, this);
    VfxKeypad::registerHandler(VFX_KEY_CODE_ARROW_RIGHT, this); 
#endif

	setLayout(VCP_SLIDER_LAYOUT_HORZ);	
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SoI", SA_stop); 
#endif
}

void VcpSlider::setThumb(VcpSliderBarThumb *thumb)
{
    if(m_thumb)
    {
        VFX_OBJ_CLOSE(m_thumb);
    }
    m_thumb = thumb;
}

void VcpSlider::setTrack(VcpSliderBarView *track)
{
    if(m_track)
    {
        VFX_OBJ_CLOSE(m_track);
    }
    m_track = track;
}

void VcpSlider::setIsHapticTouchEnabled(VfxBool state)
{
    m_thumb->setIsHapticTouchEnabled(state);        
}

VfxBool VcpSlider::getIsHapticTouchEnabled()
{
    return m_thumb->getIsHapticTouchEnabled();        
}

void VcpSlider::setBounds(const VfxRect &value)
{
    VfxRect adjustedRect = value;
    if(m_layout == VCP_SLIDER_LAYOUT_HORZ)    
    {
        m_length = value.size.width;
        adjustedRect.size.width = m_length;
        adjustedRect.size.height =  m_thumb->getSize().height;
        VfxFrame::setBounds(adjustedRect);
        m_track->setSize(m_length - (VCP_SLIDER_TRACK_MARGIN<<1), VCP_SLIDER_TRACK_HORZ_THICKNESS);		
    }
    else if(m_layout == VCP_SLIDER_LAYOUT_VERT)    
    {
        m_length = value.size.height;
        adjustedRect.size.width = m_thumb->getSize().width;
        adjustedRect.size.height =  m_length;
        VfxFrame::setBounds(adjustedRect);
        m_track->setSize(VCP_SLIDER_TRACK_VERT_THICKNESS, m_length - (VCP_SLIDER_TRACK_MARGIN<<1));		
    }
    else
    {
        VFX_DEV_ASSERT(0);
    }
	setCurrentValue(getCurrentValue()); // To reposition thumb
}

void VcpSlider::setLength(VfxS32 len)
{
    if(m_layout == VCP_SLIDER_LAYOUT_HORZ)    
    {
        setSize(len,0);
    }
    else if(m_layout == VCP_SLIDER_LAYOUT_VERT)    
    {
        setSize(0, len);
    }
    else
    {
        VFX_DEV_ASSERT(0);
    }
    VFX_LOG(VFX_INFO2, VCP_SLIDER_SET_LENGTH, len);
}


void VcpSlider::setImageFullTrack(VfxImageSrc &img)
{
    m_track->m_trackImgType = VCP_SLIDER_SINGLE_TRACK_IMG;
    m_track->m_trackBgImg = img;
    m_track->invalidate();
}

void VcpSlider::setImageCompletedPart(VfxImageSrc &img)
{
    m_track->m_trackCompletedPartImg = img;
    m_track->m_trackImgType = VCP_SLIDER_SEPARATED_TRACK_IMG;
    m_track->invalidate();
}
void VcpSlider::setImagePendingPart(VfxImageSrc &img)
{
    m_track->m_trackBgImg = img;
    m_track->m_trackImgType = VCP_SLIDER_SEPARATED_TRACK_IMG;
    m_track->invalidate();
}

void VcpSlider::setImageThumbControl(VcpStateImage &img)
{
    m_thumb->setImage(img);    
}


#if defined(VCP_SLIDER_KEY_HANDLING)
void VcpSlider::setTotalDiscreteStepsForKey(VfxU32 steps)   
{
    m_discreteStepsForKey = steps;
}
VfxU32 VcpSlider::getTotalDiscreteStepsForKey() const
{
    return m_discreteStepsForKey;
}
#endif

void VcpSlider::setTotalDiscreteStepsForPen(VfxU32 steps)
{
    m_discreteStepsForPen = steps;
    m_unitStop = (getMaxValue() - getMinValue() ) /  m_discreteStepsForPen ;
    VFX_LOG(VFX_INFO2, VCP_SLIDER_DISCRETE_MODE_SETTING, (VfxS32)(m_discreteStepsForPen*100), (VfxS32)(m_unitStop*100));
}
VfxU32 VcpSlider::getTotalDiscreteStepsForPen() const
{
    return m_discreteStepsForPen;
}
#if defined(VCP_SLIDER_KEY_HANDLING)
VfxBool VcpSlider::onKeyInput(VfxKeyEvent &event)
{
    if (event.type != VFX_KEY_EVENT_TYPE_UP)
    {
        return VFX_FALSE;
    }
    VfxFloat singleStep = (m_max - m_min)/m_discreteStepsForKey;
    VfxFloat newValue = getCurrentValue();

    if(m_layout == VCP_SLIDER_LAYOUT_HORZ)    
    {
        switch (event.keyCode)
        {    
        case VFX_KEY_CODE_ARROW_RIGHT:        
            {
                if(getMaxValue() - getCurrentValue() < singleStep)
                {
                    newValue = getMaxValue();
                }
                else
                {
                    newValue = getCurrentValue() + singleStep;
                }
                setCurrentValue(newValue);
                return VFX_TRUE;
            }
            break;
        case VFX_KEY_CODE_ARROW_LEFT:     
            {
                if(getCurrentValue() - getMinValue() < singleStep)
                {
                    newValue = getMinValue();
                }
                else
                {
                    newValue = getCurrentValue() - singleStep;
                }
                setCurrentValue(newValue);
                return VFX_TRUE;
            }
            break;
        default:
            break;		
        }
    }

    if(m_layout == VCP_SLIDER_LAYOUT_VERT)    
    {
        switch (event.keyCode)
        {    
        case VFX_KEY_CODE_ARROW_UP:        
            {
                if(getMaxValue() - getCurrentValue() < singleStep)
                {
                    newValue = getMaxValue();
                }
                else
                {
                    newValue = getCurrentValue() + singleStep;
                }
                setCurrentValue(newValue);
                return VFX_TRUE;
            }
            break;
        case VFX_KEY_CODE_ARROW_DOWN:     
            {
                if(getCurrentValue() - getMinValue() < singleStep)
                {
                    newValue = getMinValue();
                }
                else
                {
                    newValue = getCurrentValue() - singleStep;
                }
                setCurrentValue(newValue);
                return VFX_TRUE;
            }
            break;
        default:
            break;		
        }
    }
    return VfxControl::onKeyInput(event);
}
#endif /* #if defined(VCP_SLIDER_KEY_HANDLING) */


VfxFloat VcpSlider::roundToNearestStop(VfxFloat value, VfxFloat totalSteps)
{
    if(!totalSteps)
    {
        return value;
    }

    // Rounding at 3/4 of stops.
    VfxS32 steps = ((value + m_unitStop/4) - getMinValue()) * totalSteps / 
                                     (getMaxValue() - getMinValue() );

    if(steps >= totalSteps)
    {
        return getMaxValue();
    }
    return (steps*m_unitStop) + getMinValue();
}

void VcpSlider::setCurrentValue(VfxFloat value)
{
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SCV", SA_start); 
#endif	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    VfxS32 pos = 0;
    VfxS32 length = 0;
    VFX_LOG(VFX_INFO2, VCP_SLIDER_SET_VALUE_INPUT, (VfxS32)(m_max*100), (VfxS32)(100*value), (VfxS32)(100*m_min));

    if(m_discreteStepsForPen)
    {
        m_cValue = roundToNearestStop(value, m_discreteStepsForPen); 
       VFX_LOG(VFX_INFO2, VCP_SLIDER_SET_VALUE_ROUNDED, (VfxS32)(100*m_cValue));
    }
    else
    {
       m_cValue = value;
    }


    if(m_layout == VCP_SLIDER_LAYOUT_VERT)    
    {
        length = getSize().height;
    }
    else if(m_layout == VCP_SLIDER_LAYOUT_HORZ)    
    {
        length = getSize().width;
    }

	VfxFloat ratio = 0.0;
	if(m_cValue > m_max) 
	{
		m_cValue = m_max;
		ratio = 1.0;
		pos = length;		// Avoid float rounding errors on max boundary
	}
	else if(m_cValue < m_min)
	{
		m_cValue = m_min;
		ratio = 0.0;
		pos = 0;			// Avoid float rounding errors on min boundary
	}
    else if(m_max - m_min < FLOAT_EPSILON)
    {
		m_cValue = m_min;
		ratio = 0.0;
		pos = 0;			// Avoid float rounding errors on min boundary
    }
	else
	{
		ratio = ((m_cValue - m_min)/(m_max - m_min));	
        pos = length * ratio;
	}
    VFX_LOG(VFX_INFO2, VCP_SLIDER_SET_VALUE_FINALIZED, (VfxS32)(100*m_cValue));
    if(length > 0)
    {    
        ratio = ((VfxFloat)pos)/((VfxFloat)length); // Recalculating ratio for use with anchor. This would help keep it the anchor in synch with calculated position
    }
    if(m_layout == VCP_SLIDER_LAYOUT_VERT)    
    {  
        m_thumb->setAnchor(0.5, 1.0 - ratio);
        m_thumb->setPos(m_thumb->getSize().width/2, length - pos);        
        m_track->m_divider = pos;
    }
    else if(m_layout == VCP_SLIDER_LAYOUT_HORZ)    
    {
        m_thumb->setAnchor(ratio, 0.5);
        m_thumb->setPos(pos, m_thumb->getSize().height/2);        
        m_track->m_divider = pos;
    }    
     VFX_LOG(VFX_INFO2, VCP_SLIDER_SET_VALUE_POSITION_FINALIZED, pos);

    m_track->invalidate();
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SCV", SA_stop); 
#endif		
}

void VcpSlider::setMaxValue(VfxFloat value)
{
    m_max = value;
}

void VcpSlider::setMinValue(VfxFloat value)
{
    m_min = value;
}

void VcpSlider::setLayout(VcpSliderLayoutEnum layout)
{  
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SsL", SA_start); 
#endif	
    m_layout = layout;
    setLength(getLength());
    if(m_layout == VCP_SLIDER_LAYOUT_VERT)    
    {
       m_track->m_trackImgType = VCP_SLIDER_SINGLE_TRACK_IMG;
        m_track->setAnchor(0.5, 0);
        m_track->setPos((getSize().width/2), VCP_SLIDER_TRACK_MARGIN);
       m_track->m_trackBgImg = VfxImageSrc(VCP_IMG_SLIDER_VERT_BG);
       m_track->m_trackCompletedPartImg = VfxImageSrc(VCP_IMG_SLIDER_VERT_H);
    }
    else if(m_layout == VCP_SLIDER_LAYOUT_HORZ)    
    {
        m_track->m_trackImgType = VCP_SLIDER_SEPARATED_TRACK_IMG;
        m_track->setAnchor(0, 0.5);
        m_track->setPos(VCP_SLIDER_TRACK_MARGIN, getSize().height/2);
        m_track->m_trackBgImg = VfxImageSrc(VCP_IMG_SLIDER_HRZT_BG);
        m_track->m_trackCompletedPartImg = VfxImageSrc(VCP_IMG_SLIDER_HRZT_H);
    }    
    setCurrentValue(getCurrentValue()); // To reposition thumb
#if defined(__MAUI_SOFTWARE_LA__)
	SLA_CustomLogging("SsL", SA_stop); 
#endif	    
}   

VfxFloat VcpSlider::PositionToValue(VfxS32 position)
{
    VfxFloat value;
	if(position > getLength())
	{
		value = getMaxValue();	// Avoid float rounding errors on max boundary		
	}
	else if(position < 0)
	{
		value = getMinValue();	// Avoid float rounding errors on min boundary		
	}
    else
    {
        value = ((VfxFloat)position * ((getMaxValue() - getMinValue()) / ((VfxFloat)(getLength() )) ) ) + getMinValue();
    } 
    if(VCP_SLIDER_LAYOUT_VERT == getLayout())
    {
        value = (getMaxValue() + getMinValue() ) - value;
    }
    return value;
}

VfxS32 VcpSlider::ValueToPosition(VfxFloat value)
{
    VfxS32 position;

    value = value < getMaxValue()  ? value : getMaxValue();
    value = value < getMinValue() ? getMinValue() : value;

    position = value * (VfxS32)(( (VfxFloat)getLength() ) / (getMaxValue() - getMinValue()));
    if(VCP_SLIDER_LAYOUT_VERT == getLayout())
    {
        position = getLength() - position;
    }
    return position;
}


