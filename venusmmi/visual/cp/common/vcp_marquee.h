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
 *  vcp_marquee.h
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Marquee component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_MARQUEE_H__
#define __VCP_MARQUEE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxControl
#include "vfx_control.h"

#include "vfx_font_desc.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_animation.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define VCP_MARQUEE_DEFAULT_FONT                VFX_FONT_DESC_MEDIUM
#define VCP_MARQUEE_DEFAULT_TEXT_COLOR          VFX_COLOR_WHITE
#define VCP_MARQUEE_DEFAULT_TEXT_BORDER_COLOR   VFX_COLOR_BLACK


/***************************************************************************** 
 * Class VcpMarquee
 *****************************************************************************/

/*
 *  VcpMarquee provide marquee scrolling for text and image.
 *
 *  1. It scrolls in horizontal direction with various configurations.
 *
 *  2. The scrolling width is decided by 'this->m_propertyBounds' and the width of the movable text/image.
 *
 * EXAMPLE
 * <code>
 *  VcpMarquee *m;
 *  VFX_OBJ_CREATE(m, VcpMarquee, this);
 *  m->setBounds(VfxRect(0, 0, 100, 20)); // 'bounds' is important for marquee
 *  m->setMovableFrame(VFX_WSTR("Hello Marquee!"));
 *  m->startScroll();
 * </code>
 */
class VcpMarquee : public VfxControl
{
    VFX_DECLARE_CLASS(VcpMarquee);

// Constructor/Destructor
public:
    // <group DOM_Marquee_VcpMarquee_Constructor/Destructor>
    //  Constructor
    VcpMarquee();

// Typedef
public:
    // <group DOM_Marquee_VcpMarquee_Typedef>
    // Enum for the direction property
    enum DirectionEnum
    {
        DIRECTION_NATURAL,  // Scroll according to the current language setting (L2R or R2L)
        DIRECTION_LEFT,     // Scrolling from right to left (Combined with HALIGN_LEFT preferred)
        DIRECTION_RIGHT     // Scrolling from left to right (Combined with HALIGN_RIGHT preferred)
    };

    // <group DOM_Marquee_VcpMarquee_Typedef>
    // Enum for the halign property
    enum HalignEnum
    {
        HALIGN_NATURAL,     // Align according to the current language setting (L2R or R2L)
        HALIGN_LEFT,        // Left
        HALIGN_CENTER,      // Center
        HALIGN_RIGHT        // Right
    };

    // <group DOM_Marquee_VcpMarquee_Typedef>
    // Enum for the valign property
    enum ValignEnum
    {
        VALIGN_TOP,         // Top
        VALIGN_CENTER,      // Center
        VALIGN_BOTTOM       // Bottom
    };

    // <group DOM_Marquee_VcpMarquee_Typedef>
    // Enum for the scroll mode property. Similar to HTML Marquee tag definition.
    enum ScrollModeEnum
    {
        SCROLL_MODE_STANDARD,   // Standard mode similar to Pluto UI; there are two identical frames on screen scrolling head-to-tail. 
        SCROLL_MODE_SLIDE,      // The scrolling stops when the leading part reaches the end (loop = 1 is preferred in this mode)
        SCROLL_MODE_ALTERNATE   // The movable frame bounces inside the bounds back and forth repeatedly
    };

    // <group DOM_Marquee_VcpMarquee_Enum>
    // Constants
    enum 
    {
        DEFAULT_SPEED = 30,             // Default pixels scrolled per second
        DEFAULT_START_DELAY = 1400,     // Default time delay before scrolling (sync with Pluto UI)
        DEFAULT_SCROLL_GAP = 32         // Default spacing between two frames in SCROLL_MODE_STANDARD
    };

// Property
public:
    // <group DOM_Marquee_VcpMarquee_Property>
    // Speed property - number of pixels scrolled per second. (default DEFAULT_SPEED)
    virtual VfxS32 getSpeed() const;
    // <group DOM_Marquee_VcpMarquee_Property>
    // Loop property - number of loops. 0 for infinite loop. (default 0)
    virtual VfxS32 getLoop() const;

    // <group DOM_Marquee_VcpMarquee_Property>
    VfxWString getText() const;

    // <group DOM_Marquee_VcpMarquee_Property>
    // Start-Delay property - Initial time delay before scrolling (default DEFAULT_START_DELAY)
    virtual VfxMsec getStartDelay() const;
    // <group DOM_Marquee_VcpMarquee_Property>
    // Direction property - Scrolling direction (use 'DirectionEnum'; default DIRECTION_NATURAL)
    virtual DirectionEnum getDirection() const;
    // <group DOM_Marquee_VcpMarquee_Property>
    // Scroll-Mode property (use 'ScrollModeEnum'; default SCROLL_MODE_STANDARD)
    virtual ScrollModeEnum getScrollMode() const;
    // <group DOM_Marquee_VcpMarquee_Property>
    // Horizontal-Align property (use 'HalignEnum'; default HALIGN_NATURAL)
    virtual HalignEnum getHalign() const;
    // <group DOM_Marquee_VcpMarquee_Property>
    // Vertically-Align property (use 'ValignEnum'; default VALIGN_CENTER)
    virtual ValignEnum getValign() const;
    
    // <group DOM_Marquee_VcpMarquee_Property>
    virtual void setSpeed(VfxS32 value);
    // <group DOM_Marquee_VcpMarquee_Property>
    virtual void setLoop(VfxS32 value);
    // <group DOM_Marquee_VcpMarquee_Property>
    virtual void setStartDelay(VfxMsec value);
    // <group DOM_Marquee_VcpMarquee_Property>
    virtual void setDirection(DirectionEnum value);
    // <group DOM_Marquee_VcpMarquee_Property>
    virtual void setScrollMode(ScrollModeEnum value);
    // <group DOM_Marquee_VcpMarquee_Property>
    virtual void setHalign(HalignEnum value);
    // <group DOM_Marquee_VcpMarquee_Property>
    virtual void setValign(ValignEnum value);

// Signal
public:    
    // <group DOM_Marquee_VcpMarquee_Event>
    // Signal when the scrolling is finished
    VfxSignal1 <VcpMarquee *> m_signalScrollFinished;

// Method
public:  
    // <group DOM_Marquee_VcpMarquee_Method>
    //  Starts the scrolling.
    void startScroll();
    // <group DOM_Marquee_VcpMarquee_Method>
    //  Stops the scrolling.
    void stopScroll();
    
    // <group DOM_Marquee_VcpMarquee_Method>
    // Checks if the marquee needs scrolling.
    // RETURNS: VFX_TRUE if movable frame is wider than the marquee; otherwise, VFX_FALSE
    VfxBool needScroll();
    // <group DOM_Marquee_VcpMarquee_Method>
    // Checks if the marquee is scrolling now.
    // RETURNS: VFX_TRUE if the marquee is scrolling now; otherwise, VFX_FALSE
    VfxBool isScrolling() const 
    {
        return m_isScrolling;
    }
    
    // <group DOM_Marquee_VcpMarquee_Method>
    // Create a movable text frame. The old content will be released.
    
    void setMovableFrame(
        const VfxWChar *text,                             // [IN] text to be scrolled, 
        const VfxFontDesc &font = VCP_MARQUEE_DEFAULT_FONT);  // [IN] font

    void setMovableFrame(
        const VfxResId resId,                             // [IN] text to be scrolled, 
        const VfxFontDesc &font = VCP_MARQUEE_DEFAULT_FONT);  // [IN] font

    void setMovableFrame(
        const VfxWString &text,                             // [IN] text to be scrolled, 
        const VfxFontDesc &font = VCP_MARQUEE_DEFAULT_FONT  // [IN] font
    );

    // <group DOM_Marquee_VcpMarquee_Method>
    // Change the text color of movable text frame
    void setTextColor(
        const VfxColor &textColor   // [IN] Text color to set
    );
    
    // <group DOM_Marquee_VcpMarquee_Method>
    // Change the text color of movable text frame
    void setTextColor(
        const VfxColor &textColor,  // [IN] Text color to set
        const VfxColor &borderColor // [IN] Text border color to set
    );

    // <group DOM_Marquee_VcpMarquee_Method>
    // Release the previous movable frame and related data
    void clearMovableFrame();
      
	// <group DOM_Marquee_VcpMarquee_Method>
    // Sets Auto Resized flag
	void setAutoResized(VfxBool Value)
	{
		m_autoResized = Value;
	}
    // <group DOM_Marquee_VcpMarquee_Method>
    // Gets Auto Resized flag
	VfxBool getAutoResized()
	{
		return m_autoResized;
	}
      
	void setIsScrollAlways(VfxBool value)
	{
		m_scrollAlways = value;
	}

	VfxBool getIsScrollAlways()
	{
		return m_scrollAlways;
	}
      
// Method
protected:
    // <group DOM_Marquee_VcpMarquee_Method>
    // Use a pre-created frame to scroll, which will be released later by marquee class.
    // clearMovableFrame() is invoked in this method.
    void setMovableFrame(
        VfxFrame *frame,            // [IN] first frame to be scrolled
        VfxFrame *frame2 = NULL     // [IN] second frame to be scrolled. Typically its content is identical to 'frame'. Required in SCROLL_MODE_STANDARD.
    );

// Override
protected: 
    // <group DOM_Marquee_VcpMarquee_Override>
    // Component initialization
    virtual void onInit();
    // <group DOM_Marquee_VcpMarquee_Override>
    // Component deinitialization    
    virtual void onDeinit();

// Implementation
private:
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // The frame to be scrolled inside the marquee
    VfxFrame *m_movableFrame;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // The frame scrolling after 'm_movableFrame'. (Only used in SCROLL_MODE_STANDARD)
    VfxFrame *m_movableFrame2;

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Scrolling timeline for 'm_movableFrame'
    VfxS32Timeline *m_scrollTimeline;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Scrolling timeline for 'm_movableFrame2' (Only used in SCROLL_MODE_STANDARD)
    VfxS32Timeline *m_scrollTimeline2;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Scrolling timeline for 'm_movableFrame' (Only used in SCROLL_MODE_STANDARD)
    VfxS32Timeline *m_scrollTimeline3;

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Is scrolling now
    VfxBool m_isScrolling;

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Start timelines
    void startTimeline();
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Stop timelines    
    void stopTimeline();    

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Re-position the movable frame according to the alignment setting
    void layoutMovableFrame();
   
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Get the bounds of movable frame
    inline VfxRect getMovableBounds() const {return m_movableFrame == NULL ? VFX_RECT_ZERO : m_movableFrame->getBounds();}
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Get marquee bounds
    inline VfxRect getMarqueeBounds() const {return getBounds(); }

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Compute timeline duration by current speed
    // RETURNS: milliseconds
    VfxS32 computeTimelineDuration(
        VfxS32 distance // The moving distance
    );

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Get the current scrolling direction according to m_propertyDirection and language setting
    // RETURNS: Only DIRECTION_LEFT and DIRECTION_RIGHT
    DirectionEnum getScrollDirection();
    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Get the current alignment mode according to m_propertyHalign, language setting, and whether it needs scrolling
    // RETURNS: HALIGN_LEFT, HALIGN_RIGHT, HALIGN_CENTER
    HalignEnum getHAlign();

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Callback when timeline is stopped
    void onTimelineStop(VfxBaseTimeline *timeline, VfxBool isCompleted);

    // <group DOM_Marquee_VcpMarquee_Implementation>
    // Bounds changed callback 
    void onPropertyBoundsChanged(VfxFrame *source, const VfxRect &oldBounds);
    
// Implementation
private:
    // <group DOM_Marquee_VcpMarquee_Implementation>
    VfxS32 m_speed;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    VfxS32 m_loop;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    VfxMsec m_startDelay;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    DirectionEnum m_direction;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    ScrollModeEnum m_scrollMode;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    HalignEnum m_halign;
    // <group DOM_Marquee_VcpMarquee_Implementation>
    ValignEnum m_valign;
    // <group DOM_Marquee_VcpMarquee_Implementation>
	VfxBool	  m_autoResized;
	// <group DOM_Marquee_VcpMarquee_Implementation>
	VfxBool	  m_scrollAlways;
};

#endif /* __VCP_MARQUEE_H__ */

