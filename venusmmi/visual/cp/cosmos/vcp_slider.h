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
*  vcp_slider.h
*
* Project:
* --------
*  Venus UI Components
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
*****************************************************************************/

#ifndef __VCP_SLIDER_H__
#define __VCP_SLIDER_H__

/***************************************************************************** 
* Include
*****************************************************************************/
#include "vcp_image_button.h"

#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_draw_context.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_signal.h"

#if defined(__MMI_VUI_COSMOS_CP__)

/***************************************************************************** 
* Define
*****************************************************************************/

//#define VCP_SLIDER_KEY_HANDLING

#ifdef __MMI_MAINLCD_320X480__     
#define VCP_SLIDER_TRACK_HORZ_THICKNESS 10
#define VCP_SLIDER_TRACK_VERT_THICKNESS 12
#define VCP_SLIDER_THUMB_WIDTH    28
#define VCP_SLIDER_THUMB_HEIGHT    28
#define VCP_SLIDER_TOUCH_MINIMAL_SIZE 40
#elif defined(__MMI_MAINLCD_480X800__)        
#define VCP_SLIDER_TRACK_HORZ_THICKNESS 17
#define VCP_SLIDER_TRACK_VERT_THICKNESS 22
#define VCP_SLIDER_THUMB_WIDTH    49
#define VCP_SLIDER_THUMB_HEIGHT    49
#define VCP_SLIDER_TOUCH_MINIMAL_SIZE 80
#else 
#define VCP_SLIDER_TRACK_HORZ_THICKNESS 10
#define VCP_SLIDER_TRACK_VERT_THICKNESS 12
#define VCP_SLIDER_THUMB_WIDTH    28
#define VCP_SLIDER_THUMB_HEIGHT    28
#define VCP_SLIDER_TOUCH_MINIMAL_SIZE 40
#endif

enum VcpSliderImgType
{
    VCP_SLIDER_SINGLE_TRACK_IMG,
    VCP_SLIDER_SEPARATED_TRACK_IMG
};

// Slider Layout Enum. 
// <group DOM_Slider_Macro&Enum_Enum
enum VcpSliderLayoutEnum 
{
    VCP_SLIDER_LAYOUT_VERT, // Vertical slider
    VCP_SLIDER_LAYOUT_HORZ, // Horizontal slider 

    VCP_SLIDER_LAYOUT_DEFAULT = VCP_SLIDER_LAYOUT_HORZ
};


enum VcpSliderModeEnum 
    // Deprecated
{
    VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS,
    VCP_SLIDER_MODE_INTERACTIVE_DISCRETE,
    VCP_SLIDER_MODE_NON_INTERACTIVE,

    VCP_SLIDER_MODE_DEFAULT    
};

/***************************************************************************** 
* Class VcpSliderBarView
* VcpSliderBarView is the frame that acts as the track-path of the slider
* In general use, VcpSlider creates an instance of VcpSliderBarView, 
* But, it can be inherited to customize, and then attached to your VcpSlider 
* object using VcpSlider::setTrack()
*****************************************************************************/
class  VcpSliderBarView : public VfxControl
{
    VFX_DECLARE_CLASS(VcpSliderBarView);

    // Constructor / Destructor
public:    
    // Default constructor.
    // <group DOM_Slider_VcpSliderBarView_Constructor/Destructor>
    VcpSliderBarView();
    virtual ~VcpSliderBarView();

    // <group DOM_Slider_VcpSliderBarView_Override>
    virtual void onInit();
    
    // <group DOM_Slider_VcpSliderBarView_Override>    
    virtual VfxBool onPenInput(VfxPenEvent &event);    
    
    // <group DOM_Slider_VcpSliderBarView_Override>        
    virtual void onDraw(VfxDrawContext &dc);

// Variables
    
    // <group DOM_Slider_VcpSliderBarView_Implementation>    
    VfxS32 m_divider;
    
    // <group DOM_Slider_VcpSliderBarView_Implementation>    
    VfxImageSrc m_trackBgImg;
    
    // <group DOM_Slider_VcpSliderBarView_Implementation>    
    VfxImageSrc m_trackCompletedPartImg;
    
    // <group DOM_Slider_VcpSliderBarView_Implementation>    
	VcpSliderImgType m_trackImgType;
};

/***************************************************************************** 
* Class VcpSliderBarThumb
* VcpSliderBarThumb is the frame that acts as the thumb-control of the slider
* In general use, VcpSlider creates an instance of VcpSliderBarThumb, 
* But, it can be inherited to customize, and then attached to your VcpSlider 
* object using VcpSlider::setThumb()
*****************************************************************************/
class  VcpSliderBarThumb : public VcpImageButton
{
    VFX_DECLARE_CLASS(VcpSliderBarThumb);

public:
    // Default constructor.
    // <group DOM_Slider_VcpSliderBarThumb_Constructor/Destructor>
    VcpSliderBarThumb(){}
    virtual ~VcpSliderBarThumb(){}

    // <group DOM_Slider_VcpSliderBarThumb_Override>
	virtual VfxBool onPenInput(VfxPenEvent &event);

    // <group DOM_Slider_VcpSliderBarThumb_Implementation>
    VfxPoint m_downPos;
};

/***************************************************************************** 
* Class VcpSlider
*****************************************************************************/
class VcpSlider : public VfxControl
{
    VFX_DECLARE_CLASS(VcpSlider);

public:    
    // Default constructor.
    // <group DOM_Slider_VcpSlider_Constructor/Destructor>
    VcpSlider();
    virtual ~VcpSlider();

    // <group DOM_Slider_VcpSlider_Override>
    virtual void onInit();
    // <group DOM_Slider_VcpSlider_Override>
    virtual void setBounds(const VfxRect &value);        

#if defined(VCP_SLIDER_KEY_HANDLING)
    // <group DOM_Slider_VcpSlider_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
#endif
    // Property

    // Set Vertical or horizontal Layout 
    // Default = VCP_SLIDER_LAYOUT_HORZ
    // <group DOM_Slider_VcpSlider_Property>
    virtual void setLayout(VcpSliderLayoutEnum layout);     
    
    // Get current Layout 
    // <group DOM_Slider_VcpSlider_Property>
    VcpSliderLayoutEnum getLayout()
    {
        return m_layout;
    }

    // Set frame length [Mandatory]
    // Note: Please use this property instead of directly setting the the frame bounds.
    // It will automatically set the required bounds of slider.
    // If layout is horizontal, length = frame width
    // If layout is vertical, length = frame height
    // Default = LCD_WIDTH
    // <group DOM_Slider_VcpSlider_Property>
    virtual void setLength(VfxS32 len);
    
    // Get current length 
    // <group DOM_Slider_VcpSlider_Property>    
    VfxS32 getLength()
    {
        return m_length;
    }

    // Maximum value of total slider range.
    // This is the abstract (not-on-screen) scale that application uses to comunicate with slider.
    // Slider would automatically map this scale to actual on-screen length of Slider Frame.    
    // The range is set in floating point numbers.
    // Default = 1.0
    // <group DOM_Slider_VcpSlider_Property>
    virtual void setMaxValue(VfxFloat value);
    
    // Get max value
    // <group DOM_Slider_VcpSlider_Property>
    VfxFloat getMaxValue()
    {
        return m_max;
    }

    // Minimum value of total slider range.
    // This is the abstract (not-on-screen) scale that application uses to comunicate with slider.
    // Slider would automatically map this scale to actual on-screen length of Slider Frame.    
    // The range is set in floating point numbers.        
    // Default = 0
    // <group DOM_Slider_VcpSlider_Property>
    virtual void setMinValue(VfxFloat value);
    
    // Get min value
    // <group DOM_Slider_VcpSlider_Property>
    VfxFloat getMinValue()
    {
        return m_min;
    }

    // Current value in total slider range.
    // This defines the spot where thumb-control is located, dividing the total Slider length.      
    // The range is set in floating point numbers.            
    // Default = Minimum value
    // <group DOM_Slider_VcpSlider_Property>
    virtual void setCurrentValue(VfxFloat value);
    
    // Get current value
    // <group DOM_Slider_VcpSlider_Property>
    VfxFloat getCurrentValue()
    {
        return m_cValue;
    }

    // Set a customized slider track frame
    // <group DOM_Slider_VcpSlider_Property>
    void setTrack(VcpSliderBarView *track);
    
    // Set a customized slider thumb frame
    // <group DOM_Slider_VcpSlider_Property>
    void setThumb(VcpSliderBarThumb *thumb);
    
    // Set a custom image for complete track background.
    // This image should be in 9-slice format, for resizing.
    // If this image is set, same image would be used on both sides of the thumb-control;
    // i.e. completed and pending parts of track would not look different.
    // <group DOM_Slider_VcpSlider_Property>
    void setImageFullTrack(VfxImageSrc &img);
    
    // Set a custom image for completed part of track background.    
    // Completed part is the left side in case of horizontal layout & bottom part in vertical layout
    // This image should be in 9-slice format, for resizing.
    // If this image is set, two sides of thumb control would have different background images.
    // <group DOM_Slider_VcpSlider_Property>
    void setImageCompletedPart(VfxImageSrc &img);
    
   	// Set a custom image for pending part of track background.    
    // Pending part is the right side in case of horizontal layout & top part in vertical layout
    // This image should be in 9-slice format, for resizing.
    // If this image is set, two sides of thumb control would have different background images
    // <group DOM_Slider_VcpSlider_Property>
    void setImagePendingPart(VfxImageSrc &img);

    // Set a custom image for thumb-control. 
    // This is a small image button which accepts the touch inputs to move around.
    // <group DOM_Slider_VcpSlider_Property>
    void setImageThumbControl(VcpStateImage &img);

// DOM-NOT_FOR_SDK-BEGIN
    // Set the mode (DEPRECATED)
    // Default =  VCP_SLIDER_MODE_NON_INTERACTIVE
    void setSliderMode(VcpSliderModeEnum mode)
    {
        // Mode property is now deprecated. Please use the signals to achieve same results.
    }
    VcpSliderModeEnum getSliderMode()
    {
        return m_mode; // Mode property is now deprecated
    }
// DOM-NOT_FOR_SDK-END

    // Set total number of steps in which slider movement is divided, with touch interface
    // If it is set to N, then slider will move in steps of size: total-length/N.
    // To use slider in a discrete-step style, set a non-zero value of this property
    // To use Slider in continuous style, set this property to 0
    // Default =  0
    // <group DOM_Slider_VcpSlider_Property>
    void setTotalDiscreteStepsForPen(VfxU32 steps);

    // Get total number of steps in which slider movement is divided.
    // <group DOM_Slider_VcpSlider_Property>
    VfxU32 getTotalDiscreteStepsForPen() const;

#if defined(VCP_SLIDER_KEY_HANDLING)
    // Set total number of steps in which slider movement is divided, with keypad interface
    // If it is set to N, then slider will move in steps of size: total-length/N.
    // To use slider in a discrete-step style, set a non-zero value of this property
    // To use Slider in continuous style, set this property to 0
    // Default =  0
    // Note : Only available in MRE (projects with navigation key support)
    // <group DOM_Slider_VcpSlider_Property>    
    void setTotalDiscreteStepsForKey(VfxU32 steps);

    // Returns the value of TotalDiscreteStepsForKey property.
    // See also : setTotalDiscreteStepsForKey
    // Note: Only available in MRE (projects with navigation key support)
    // <group DOM_Slider_VcpSlider_Property>
    VfxU32 getTotalDiscreteStepsForKey() const;
#endif

    // Enable/Disable haptic touch feedback
    // <group DOM_Slider_VcpSlider_Property>
    // Default: VFX_TRUE
    void setIsHapticTouchEnabled(VfxBool state);

    // Returns whther haptic touch feedback is Enabled or Disabled
    // <group DOM_Slider_VcpSlider_Property>    
    VfxBool getIsHapticTouchEnabled();

    // Events

    VfxSignal3 <
        VfxObject *, // Slider pointer
        VfxFloat, // Old Value
        VfxFloat // New Value
    > m_signalUserChangedValue;   
//[Deprecated] Please use the next 3 signals only

    // This signal emits everytime a pen-move event causes a change in slider value.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 <
        VcpSlider *, // Slider pointer
        VfxFloat // New Value
    > m_signalThumbDrag; 
    
    // This signal emits everytime a pen-down event happens on the slider thumb control.
    // It signifies that the user has started dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 < 
        VcpSlider*, //Slider pointer
        VfxFloat // Pen down Value
    > m_signalThumbPressed;
    
    // This signal emits everytime a pen-up event happens on the slider thumb control.
    // It signifies that the user has stopped dragging the slider.
    // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 <
        VcpSlider*, //Slider pointer
        VfxFloat // Pen up Value
    > m_signalThumbReleased;
    
#if defined(VCP_SLIDER_KEY_HANDLING)
      // This signal emits everytime a key event causes a change in slider value.
      // <group DOM_Slider_VcpSlider_Event>    
    VfxSignal2 <
        VcpSlider *, //Slider pointer
        VfxFloat //New value
    > m_signalChangeByKeypad;
#endif

    // Implementation
private:
    // <group DOM_Slider_VcpSlider_Implementation>    
    VcpSliderModeEnum  m_mode;
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxBool m_state;  
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxS32 m_length;
    
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxFloat m_unitStop;
protected:    
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxFloat m_cValue;
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxFloat m_max;
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxFloat m_min;
    // <group DOM_Slider_VcpSlider_Implementation>    
    VcpSliderLayoutEnum m_layout;
#if defined(VCP_SLIDER_KEY_HANDLING)
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxU32 m_discreteStepsForKey;
#endif
    // <group DOM_Slider_VcpSlider_Implementation>    
    VfxU32 m_discreteStepsForPen;
    // <group DOM_Slider_VcpSlider_Implementation>    
    VcpSliderBarView   *m_track;
    // <group DOM_Slider_VcpSlider_Implementation>    
    VcpSliderBarThumb   *m_thumb;                           
    // <group DOM_Slider_VcpSlider_Implementation>          
    VfxFloat roundToNearestStop(VfxFloat value, VfxFloat totalSteps);
public:
   // This function converts the on-screen position of slider to the 
   // value on scale set by the client application.
   // It takes care of the rounding, in case of discrete step mode.
   // This conversion funciton is used by Slider internally
   // <group DOM_Slider_VcpSlider_Overridable>    
   virtual VfxFloat PositionToValue(VfxS32 position);
   
   // This function converts the slider's current value to its on-screen position
   // It takes care of the rounding, in case of discrete step mode.      
   // This conversion funciton is used by Slider internally
   // <group DOM_Slider_VcpSlider_Overridable>    
   virtual VfxS32 ValueToPosition(VfxFloat value);
};


#endif /* #if defined (__MMI_VUI_COSMOS_CP__)  */
#endif /* __VCP_SLIDER_H__ */

